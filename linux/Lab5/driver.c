#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>

#define MAX_BUFFER 1024
#define ANSWER_LEN 128

// Module metadata
MODULE_AUTHOR("Anton");
MODULE_DESCRIPTION("Driver");
MODULE_LICENSE("MIT");

static struct proc_dir_entry *proc_entry;

static unsigned long long number;

// 5.6 Реалізувати write, який приймає число і визначає чи просте це число .
static ssize_t custom_write(struct file *file, const char __user *buf, size_t len, loff_t *off)
{
    number = 0;

    if (len > MAX_BUFFER)
    {
        len = MAX_BUFFER;
    }

    int ret = kstrtoull_from_user(buf, len, 10, &number);
    if (ret)
    {
        char data[MAX_BUFFER] = {0};
        copy_from_user(data, buf, len);
        data[len - 1] = '\0';
        printk(KERN_ERR "Error input: \"%s\" to driver entry is wrong", data);
        return ret;
    }
    else
    {
        printk(KERN_INFO "You input: \"%d\" to driver entry", number);
        *off = len;
        return len;
    }
}

static int is_prime_number(void)
{
    if (number == 0 || number == 1)
        return 0;

    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

static ssize_t custom_read(struct file *file, char __user *buf, size_t len, loff_t *offset)
{
    if (*offset > 0)
        return 0;

    int res = is_prime_number();
    char answer[ANSWER_LEN] = {0};

    if (number == 0)
        strcat(answer, "Number is not setted up\n");
    else if (res)
        snprintf(answer, ANSWER_LEN, "Number %d is prime\n", number);
    else
        snprintf(answer, ANSWER_LEN, "Number %d is not prime\n", number);

    printk(KERN_INFO "%s", answer);
    copy_to_user(buf, answer, ANSWER_LEN);
    *offset = ANSWER_LEN;
    return ANSWER_LEN;
}

static struct proc_ops fops = {
    .proc_read = custom_read,
    .proc_write = custom_write,
};

// Custom init and exit methods
static int __init custom_init(void)
{
    proc_entry = proc_create("entry", 0666, NULL, &fops);
    printk(KERN_ERR "Proc entry loaded");
    return 0;
}

static void __exit custom_exit(void)
{
    proc_remove(proc_entry);
    printk(KERN_ERR "Proc entry unloaded");
}

module_init(custom_init);
module_exit(custom_exit);

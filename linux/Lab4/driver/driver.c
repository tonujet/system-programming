#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#define MAX_BUFFER 1024

// Module metadata
MODULE_AUTHOR("Anton");
MODULE_DESCRIPTION("Frist driver");
MODULE_LICENSE("MIT");

static struct proc_dir_entry *proc_entry;

static char data_buffer[MAX_BUFFER];

static ssize_t custom_write(struct file *file, const char __user *user, size_t size, loff_t *offset)
{
    memset(data_buffer, 0x0, sizeof(data_buffer));

    if (size > MAX_BUFFER)
    {
        size = MAX_BUFFER;
    }

    copy_from_user(data_buffer, user, size);
    printk("You write to this file: %s", data_buffer);
    return size;
}

static ssize_t custom_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
    printk(KERN_INFO "Calling custom read method.");
    char greeting[] = "Hello from driver!!!\n";
    int greeting_length = strlen(greeting);
    if (*offset > 0)
        return 0;

    copy_to_user(user_buffer, greeting, greeting_length);
    *offset = greeting_length;
    return 100;
}

static struct proc_ops fops = {
    .proc_read = custom_read,
    .proc_write = custom_write,
};

// Custom init and exit methods
static int __init custom_init(void)
{
    proc_entry = proc_create("test-driver", 0666, NULL, &fops);
    printk(KERN_INFO "Test driver loaded.");
    return 0;
}

static void __exit custom_exit(void)
{
    proc_remove(proc_entry);
    printk(KERN_INFO "Test driver unloaded");
}

module_init(custom_init);
module_exit(custom_exit);
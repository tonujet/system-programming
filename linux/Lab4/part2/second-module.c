#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>

MODULE_AUTHOR("");
MODULE_DESCRIPTION("Lab 1.2, using struct list_head");
MODULE_LICENSE("MIT");

#define LIST_LEN 13
#define MSG_PREF "TEST: "

#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);
typedef struct
{
    struct list_head lnode;
    uint16_t val;
} int_node_t;

// Макрос звільнення пам'яті
// do {}while(0)
#define ilfree(list_head)                                          \
    do                                                             \
    {                                                              \
        int_node_t *__ptr, *__tmp;                                 \
        list_for_each_entry_safe(__ptr, __tmp, (list_head), lnode) \
        {                                                          \
            kfree(__ptr);                                          \
        }                                                          \
    } while (0)

// макрос Виводу значень до консолi
#define ilprint(list_head)                             \
    do                                                 \
    {                                                  \
        int_node_t *__ptr;                             \
        print_msg("List: {");                          \
        list_for_each_entry(__ptr, (list_head), lnode) \
        {                                              \
            printk(KERN_ERR "\t%i ", __ptr->val);      \
        }                                              \
        printk(KERN_ERR "}\n");                        \
    } while (0)

// Ініціалізація списку
// https://elixir.bootlin.com/linux/latest/source/include/linux/list.h#L714
static struct list_head int_list = LIST_HEAD_INIT(int_list);

// 4.1 Порахувати кон'юнкцію (&) всіх елементів списку, N = 12
static void task1(void)
{
    int_node_t *ptr = list_first_entry(&int_list, typeof(*ptr), lnode);
    uint16_t res = ptr->val;
    list_for_each_entry_continue(ptr, &int_list, lnode)
    {
        res &= ptr->val;
    }

    printk(KERN_ERR "Logical AND: %i", res);
}

// 4.2 Знайти Найбільший значення в списку, N = 16
static void task2(void)
{
    int_node_t *ptr = list_first_entry(&int_list, typeof(*ptr), lnode);
    uint16_t max = ptr->val;
    list_for_each_entry_continue(ptr, &int_list, lnode)
    {
        uint16_t val = ptr->val;
        if (max < val)
            max = val;
    }

    printk(KERN_ERR "Max value: %i", max);
}

// 4.3 Знайти найеншее значення в списку, N = 13
static void task3(void)
{
    int_node_t *ptr = list_first_entry(&int_list, typeof(*ptr), lnode);
    uint16_t min = ptr->val;
    list_for_each_entry_continue(ptr, &int_list, lnode)
    {
        uint16_t val = ptr->val;
        if (min > val)
            min = val;
    }

    printk(KERN_ERR "Min value: %i", min);
}

// 4.4 Поділити елементи списку на число M = 25, N = 9
static void task4(void)
{
    int_node_t *ptr;
    list_for_each_entry(ptr, &int_list, lnode)
    {
        ptr->val /= 9;
    }

    print_msg("Divided by 9: ");
    ilprint(&int_list);
}

// 4.5 Зрушити елементи списку на 1 біт вліво, N = 12
static void task5(void)
{
    int_node_t *ptr;
    list_for_each_entry(ptr, &int_list, lnode)
    {
        ptr->val <<= 1;
    }

    print_msg("Left shift: ");
    ilprint(&int_list);
}

// 4.6 Зрушити елементи списку на 1 біт вправо, N = 12
static void task6(void)
{
    int_node_t *ptr;
    list_for_each_entry(ptr, &int_list, lnode)
    {
        ptr->val >>= 1;
    }

    print_msg("Rigth shift: ");
    ilprint(&int_list);
}

// 4.7 Інвертувати елементи списку, N = 10
static void task7(void)
{
    int_node_t *ptr;
    list_for_each_entry(ptr, &int_list, lnode)
    {
        ptr->val = ~ptr->val;
    }

    print_msg("Inversion: ");
    ilprint(&int_list);
}

static int __init list_module_init(void)
{
    int i;
    int ret = 0;
    print_msg("List allocation start...\n");

    // Виділення памяті під елементи списку
    for (i = 0; i < LIST_LEN; ++i)
    {
        int_node_t *ptr = (int_node_t *)kmalloc(sizeof(*ptr), GFP_KERNEL);
        if (!ptr)
        {
            print_msg("Can't alloc memory\n");
            ret = -ENOMEM;
            goto alloc_err;
        }

        // Функція для роботи
        get_random_bytes(&ptr->val, sizeof(ptr->val));
        list_add_tail(&ptr->lnode, &int_list);
    }

    print_msg("List allocation finish\n");
    ilprint(&int_list);
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    return 0;
alloc_err:
    ilfree(&int_list);
    return ret;
}

static void __exit list_module_exit(void)
{
    ilfree(&int_list);
    print_msg("Hasta la vista, Kernel!\n");
}

module_init(list_module_init);
module_exit(list_module_exit);
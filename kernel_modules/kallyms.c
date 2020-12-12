/*
 * @file	hello.c
 * @details	Simple linux kernel module
 * @author	smalinux<xunilams@gmail.com>
 *
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kallsyms.h>
#include <linux/pid.h>
#include <linux/sched.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("smalinux <xunilams@gmail.com>");

#define MODULE_NAME "hello"

static int hello_init(void)
{
	struct task_struct * p;
	pr_info(MODULE_NAME ": module loaded!\n");

	p = (void *)kallsyms_lookup_name("init_struct");
	printk("PID: %d\n", p->pid);
	return 0;
}

static void hello_exit(void)
{
	pr_info(MODULE_NAME ": module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);

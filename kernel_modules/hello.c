/* https://cirosantilli.com/linux-kernel-module-cheat#qemu-buildroot-setup-getting-started */

#include <linux/module.h>
#include <linux/kernel.h>

void before(void) {
	pr_err("Before fuck\n");
}

void after(void) {
	pr_err("After fuck\n");
}


static int myinit(void)
{
	pr_info("hello init\n");
	/* 0 for success, any negative value means failure,
	 * E* consts if you want to specify failure cause.
	 * https://www.linux.com/learn/kernel-newbie-corner-loadable-kernel-modules-coming-and-going */
	before();
	dump_stack();
	after();
	return 0;
}

static void myexit(void)
{
	pr_info("hello exit\n");
}

module_init(myinit)
module_exit(myexit)
MODULE_LICENSE("GPL");

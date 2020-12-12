/* https://cirosantilli.com/linux-kernel-module-cheat#kernel-panic-and-oops */

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
	pr_info("oops myinit\n");
	before();
	*(int *)0 = 0;
	after();
	pr_info("oops after\n");
	return 0;
}

static void myexit(void)
{
	pr_info("oops myexit\n");
}

module_init(myinit)
module_exit(myexit)
MODULE_LICENSE("GPL");

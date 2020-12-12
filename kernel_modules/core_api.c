/*
 * @file	core_api.c
 * @details	A simple practical uses of Documentation/core-api/kernel-api.rst
 * @author	smalinux
 *
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("smalinux <xunilams@gmail.com>");

#define MODULE_NAME "core_api"

static int hello_init(void)
{
	pr_info( MODULE_NAME ": Module loaded!\n");

/****************************************************************************
 * String Conversions
 ***************************************************************************/
	
	/*
	 * simple_strto<foo>
	 * 	simple_strtoul
	 * 	simple_strtol
	 * 	simple_strtoull
	 * 	simple_strtull
	 */
	char *s = "123456789";
	unsigned long long num;
	num = simple_strtoull(s, &s, 10);
	printk("num: %llu \n", num);
	/*
	 * num_to_str
	 */
	/***********************************/
	 char NTS_buf[10];
  int NTS_size = 10;
      unsigned long long NTS_num = 123456789;
           int NTS_width = 10;
           int (*fun_ptr)(char *NTS_buf, int NTS_size,
                   unsigned long long NTS_num, unsigned int NTS_width) = (void*)kallsyms_lookup_name("num_to_str");
           fun_ptr(NTS_buf, NTS_size, NTS_num, NTS_width);
           printk("num_to_str = %s \n", NTS_buf); 
           /***********************************/



	return 0;
}

static void hello_exit(void)
{
	pr_info( MODULE_NAME ": Module unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);

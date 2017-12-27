#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/fs.h>
void listar(struct seq_file *m, struct task_struct *s, int sum)
{
   
 struct list_head *list;
    struct task_struct *task;
    char esttate[16];
    int i;
    for (i = 0; i < sum; i++)
    if(s->state == TASK_RUNNING){
	strcpy(esttate,"Corriendo");        
    }else if(s->state == TASK_STOPPED){
     	strcpy(esttate,"Parado");      
    }else if(s->state == TASK_INTERRUPTIBLE){
	strcpy(esttate,"Duermiendo");      
    }else if(s->state == TASK_UNINTERRUPTIBLE){
	strcpy(esttate,"Duermiendo");    
    }else if(s->state == EXIT_ZOMBIE){
	strcpy(esttate,"Sombie");   
    }else{
	strcpy(esttate,"o");   
    }
         
    seq_printf(m,"PID:%d\t-NAME:%s\t-STATE:%d-%s\n" , s->pid, s->comm, (int)s->state,esttate);
    sum = sum + strlen(s->comm);
    list_for_each(list, &s->children) {
        task = list_entry(list, struct task_struct, sibling);
        listar(m, task, sum);
    }
}


static int cpu_proc_show(struct seq_file *m, void *v) {
  struct task_struct *raiz = current; 
  seq_printf(m, "******************************************start***********************\n");
  seq_printf(m, "*201318565*\n");
  seq_printf(m, "*Gilberto Antonio Rosales Vaquin*\n");
  seq_printf(m, "*Debian 9*\n");
  seq_printf(m, "******************PROCESOS******************\n");
  while (raiz->pid != 1)
  	raiz = raiz->parent; 
  listar(m, raiz, 0);
  seq_printf(m, "******************************************end*************************\n");
  return 0;
}

static int cpu_proc_open(struct inode *inode, struct  file *file) {
  return single_open(file, cpu_proc_show, NULL);
}

static const struct file_operations cpu_proc_fops = {
  .owner = THIS_MODULE,
  .open = cpu_proc_open,
  .read = seq_read,
  .llseek = seq_lseek,
  .release = single_release,
};

static int __init cpu_proc_init(void) {
  proc_create("cpu_proc", 0, NULL, &cpu_proc_fops);
  printk(KERN_INFO "Gilberto Rosales\n");
  return 0;
}

static void __exit cpu_proc_exit(void) {
  remove_proc_entry("cpu_proc", NULL);
  printk(KERN_INFO "Sistemas Operativos 1\n");
}

MODULE_LICENSE("GPL");
module_init(cpu_proc_init);
module_exit(cpu_proc_exit);

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Sergiu");
MODULE_LICENSE("GPL");

/*typedef struct Persoana{

	char *Nume;
	char *Prenume;
	int varsta;
	


}Persoana;*/

typedef struct Student{

	char* Nume;
	char* Prenume;
	char* Facultate;
	int varsta;
	//Persoana* p;

}Student;





static int item11_init(void){
	 Student s= {"Fierascu" , "Sergiu", "AC", 22};
	 Student s1={"Ciceu" , "Diana", "AC" , 22};
	 Student s2={"Popescu", "Vasile", "ETC", 21};
	
	printk(KERN_INFO "item11 module has been loaded\n");
	printk(KERN_INFO "Nume: %s ", " Prenume: %s "," Facultate: %s ", " An: %d ", s.Nume,s.Prenume,s.Facultate,s.varsta);
	printk(KERN_INFO "Nume: %s ", " Prenume: %s "," Facultate: %s ", " An: %d ", s1.Nume,s1.Prenume,s1.Facultate,s1.varsta);
	printk(KERN_INFO "Nume: %s ", " Prenume: %s "," Facultate: %s ", " An: %d ", s2.Nume,s2.Prenume,s2.Facultate,s2.varsta);
	
	return 0;
}

static void item11_exit(void){
	printk(KERN_INFO "item11 module has been unloaded\n");
}

module_init(item11_init);
module_exit(item11_exit);

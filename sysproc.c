#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  // PONER EL PCB EL ESTADO DE COMO HE MUERTO dentro de EXIT
  
  int exit_status;

  if (argint(0, &exit_status) < 0)
    return -1; // Error al obtener el argumento*/
  
  exit(exit_status);
  return 0;  // not reached
}

int
sys_wait(void)
{
  int * status;

  if (argptr(0, (void*)&status, sizeof(int)) < 0)
    return -1; // Error al obtener el argumento

  return wait(status);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  // El caso de un argumento negativo al llamarse a sbrk()
  if(n < 0)
  {
    growproc(n);
  } else myproc()->sz += n;
  
  /*if(growproc(n) < 0)
    return -1;*/
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_date(void)
{
  void * date_struct;

  if(argptr(0, &date_struct, sizeof(struct rtcdate)) < 0)
  {
    return -1;
  }
   cmostime((struct rtcdate*) date_struct);
   return 0;
}

int sys_getprio(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;

  //comprobar argumento
  if(pid < 0 || pid > MAX_PID)
    return -1;

  getprio(pid);
}

int sys_setprio(void)
{
  int pid, prio;

  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &prio) < 0)
    return -1;

  //comprobar argumentos
  if(pid < FIRST_PID || pid > MAX_PID || prio < HIGH_PRIO || prio > LOW_PRIO)
    return -1;
    
  setprio(pid,prio);
}




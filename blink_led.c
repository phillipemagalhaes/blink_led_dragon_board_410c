#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>



void setup (void)

{
    int fd;

    chmod ("/sys/class/gpio/gpio36/export",S_IROTH|S_IWOTH ); 
 
    fd = open("/sys/class/gpio/export", O_WRONLY);
    write(fd, "36", 2);
    close(fd);
 
    chmod ("/sys/class/gpio/gpio36/direction",S_IROTH|S_IWOTH );
    chmod ("/sys/class/gpio/gpio36/value",S_IROTH|S_IWOTH);   

    fd = open("/sys/class/gpio/gpio36/direction",O_WRONLY);

    write(fd, "out", 3);
    close(fd);


}

int main(int argc, const char *argv[])
{
   int fd;
   char buf[10];
   setup();
   
   while (1)
  { 

    fd = open("/sys/class/gpio/gpio36/value",O_RDONLY);
    read(fd, buf, sizeof(buf)-1);
    close(fd);	 

   if (*buf == '1') 
         strcpy(buf, "0");
   else 
         strcpy(buf, "1");
    
    fd = open("/sys/class/gpio/gpio36/value",O_WRONLY);
    write(fd, buf, 2);
    sleep(1);
    close(fd);
    	
 }
 
    return 0;
}
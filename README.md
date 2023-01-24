# GROUP PROJECT
<h1> <img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/228/printf.png"?raw=true" /> </h1>
<h1 >0x12. C -printf team project </h1>
<h3> * By: Julien Barbier, co-founder & CEO </h3>
<h3> * Project to be done in teams of 2 people (your team:Henok Aklilu and Binyam Mamo)
<h3 align="center" ><b>TASK </b></h3>
<h6>0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
     Repo:
      GitHub repository: printf</h6>
<h6>1. Education is when you read the fine print. Experience is what you get if you don't
<h6>2. With a face like mine, I do better in print
 Handle the following custom conversion specifiers:
  * b: the unsigned int argument is converted to binary</h6>
<h6>3. What one has not experienced, one will never understand in print
  Handle the following custom conversion specifiers:
   * u , o ,x and X</h6>
<h6> 4. Nothing in fine print is ever good news
   * Use a local buffer of 1024 chars in order to call write as little as possible.</h6>
  <h6>   5. My weakness is wearing too much leopard print
   handle the folloeing custom conversion specifier:
   * S : prints the string
   * Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, following by the ASCII code value in hexasecimal(upper case - always @ characters)
             
              alex@ubuntu:~/c/printf$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
Best\x0ASchool
alex@ubuntu:~/c/printf$
</h6>
<h6> 6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print
   * Handle the following conversion specifier: p.</h6>
<h6>7. The big print gives and the small print takes away
  * Handle the following flag characters for non-custom conversion specifiers:
       * + 
       *  space
       * #</h6>
 <h6>8. Sarcasm is lost in print
   * Handle the following length modifiers for non-custom conversion specifiers: 
      * l
      * h
   Conversion specifiers to handle: d, i, u, o, x, X<h/6>
 <h6>9. Print some money and give it to us for the rain forests
     * Handle the field width for non-custom conversion specifiers.</h6>
 <h6>10. The negative is the equivalent of the composer's score, and the print the performance
     * Handle the field width for non-custom conversion specifiers. </h6>
 <h6>11. It's depressing when you're still around and your albums are out of print  
      * Handle the 0 flag character for non-custom conversion specifiers.</h6>
 <h6>12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection
     * Handle the - flag character for non-custom conversion specifiers.</h6>
 <h6>13. Print is the sharpest and the strongest weapon of our party
     * Handle the following custom conversion specifier:
     * r : prints the reversed string</h6>
 <h6>14. The flood of print has turned reading into a process of gulping rather than savoring
      * Handle the following custom conversion specifier:
      * R: prints the rot13'ed string</h6>
 <h6>15. *
         All the above options work well together.</h6>


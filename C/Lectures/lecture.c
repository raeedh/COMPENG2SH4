#include <stdio.h>
#include <math.h>

/*int example1();
int example2();
int lecture5ex1();
int lecture5ex2();

int main()
{
    //example1();
    //example2();
    lecture5ex1();
    lecture5ex2();
    return 0;
}

int example1()
{
    int a = 1;
    char b = 'G';
    char myCr = b+1;
    double c = 3.14;
    printf("Hello World!\n");

    //printing the variables defined above along with their sizes
    printf("Hellow! I am a character. My value is %c and my size is %lu byte.\n", b,sizeof(b));
    //can use sizeof(b) above as well

    printf("Hellow! I am a characiter. My value is %d and my size is %lu byte.\n", b,sizeof(b));

    printf("the value of myCr is %c and the size is %lu\n", myCr, sizeof(myCr));

    printf("Hello! I am an integer. My value is %d and my size is %lu byte.\n", a,sizeof(a));

    return 0;
}

int example2()
{
    int j; double x;
    j = x = 2.45;
    printf("%d\n %lf",j,x);

    return 0;
}

int main()
{
    int i, x=0, sum=0;
    for (i=0;i<10;i++)
    {
        printf("Please input an integer:");
        scanf("%d", &x);
            if (x % 2 == 1)
                sum=sum+x;
    }
    printf("Your sum is %d", sum);
    return 0;
}


int main(void)
{
    int num, sum=0;
    printf("Please input an integer (1 to quit)\n");
    scanf("d",&num);
    while(num!=1){
        sum += num; //sum = sum + num;
        printf("Please input an integer (1 to quit)\n");
        scanf("%d",&num);
    }
    printf("The sym is %d", sum);
    return 0;
}

int lecture5ex1()
{
    int i = 0;
    while(i < 10)
    {
        i++;
        if(i % 3 == 0)
            break;
        printf("%d\n", i);
    }
}

int lecture5ex2()
{
    int i = 0;
    while(i < 10)
    {
        i++;
        if(i % 3 == 0)
            continue;
        printf("%d\n", i);
    }
}

// Topic 6: Character Arrays and Strings in C

int main() {
    char text[] = "Programming at McMaster is fun!";
    int i=0;
    int counter=0;
    
    for (i; text[i]!='\0'; i++) {
        if (text[i] == 'm' || text[i] == 'M') {
            counter++;
        }
    }

    printf("%d\n", counter); return 0;
}

int main() {
    char a[20];
    puts("Please input five characters on a line.");
    gets(a);
    printf("a[4]=%c, its integer value is %d\n", a[4], a[4]);
    printf("a[5]=%c, its integer value is %d\n", a[5], a[5]);
    puts(a); return 0;
}

int main() {
    int b[3] = {-1, -2, -3};
    printf("The memory location for b[0] has address: %p\n", &b[0]);
    printf("The memory location for b[1] has address: %p\n", &b[1]);
    printf("The memory location for b[2] has address: %p\n", &b[2]);
}
*/

typedef struct {
        float coeff;
        int power;
    }   Monom;
Monom product(Monom monoA, Monom monoB) {
    monoA.coeff *=monoB.coeff;
    monoA.power +=monoB.power;
    return monoA;
}
Monom prod_ref(Monom* p1, Monom* p2) {
    Monom monoA;
    monoA.coeff = p1 -> coeff * p2 -> coeff;
    monoA.power = p1 -> power + p2 -> power;
    return monoA;
}

int main() {
    Monom mono1 = {0.3, 4};
    Monom mono2 = {-2.3, 10};
    Monom mono3;
    // mono3 = product(mono1, mono2); 
    // mono3 = prod_ref(&mono1, &mono2);
    // mono2 = mono1;
    // printf("%lf %d", mono2.coeff, mono2.power);
    
    return 0;
}
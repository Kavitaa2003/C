#include<stdio.h>
#include<stdlib.h>

void Encrypt(char *str)
{
    while(*str != '\0')
    {
        *str = *str + 1;
        str++;
    }
}

void Decrypt(char *str)
{
    while(*str != '\0')
    {
        *str = *str - 1;
        str++;
    }
}

int main()
{
    char Arr[100] = {'\0'};
    printf("Enter the String: \n");
    scanf("%[^'\n']s",Arr);

    Encrypt(Arr);
    printf("Encrypted Data is : %s\n",Arr);

    Decrypt(Arr);
    printf("Decrypted Data is : %s\n",Arr);



    return 0;
}
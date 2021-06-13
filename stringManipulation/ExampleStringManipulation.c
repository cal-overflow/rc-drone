int main()
{
   // printf("Hello World");
    char charArray[] = "123";
    
    char newArray[sizeof(charArray)];
    int j = sizeof(newArray)-1;
    for(int i = sizeof(charArray)-1; i >= 0; i--)
    {
        newArray[j-i] = charArray[i];
        
    }
    for(int i =0; i < sizeof(newArray); i++)
    {
        printf("%c", newArray[i]);
    }


    return 0;
}
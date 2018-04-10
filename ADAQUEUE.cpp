#include <iostream>  
#include <cstring>  
using namespace std;  
int a[1000005];  
int main()  
{  
    int t, frente, tras, temp, dir, sum;  
    char num[1005];  
    while (scanf("%d", &t)!=EOF){  
        dir = 1;  
        sum = 0;  
        frente = tras = 1000005 / 2;  
        for (int i=1; i<=t; i++){  
            scanf("%s", num);  
            if (strcmp(num, "toFront") == 0){  
                scanf("%d", &temp);  
                if (sum){  
                    frente -= dir;                     
                    a[frente] = temp;  
                }  
                else  
                    a[frente] = temp;              
                sum++;  
            }  
            if (strcmp(num, "push_back") == 0){  
                scanf("%d", &temp);  
                if (sum){  
                    tras += dir;  
                    a[tras] = temp;  
                }  
                else  
                    a[tras] = temp;  
                sum++;  
            }  
            if (strcmp(num, "front") == 0){  
                if (!sum)  
                    printf("No job for Ada?\n");  
                else{  
                    printf("%d\n", a[frente]);  
                    sum--;  
                    if (sum)  
                        frente += dir;                     
                }  
            }  
            if (strcmp(num, "back") == 0){  
                if (!sum)  
                    printf("No job for Ada?\n");  
                else{  
                    printf("%d\n", a[tras]);  
                    sum--;  
                    if (sum)  
                        tras -= dir;      
                }                     
            }  
            if (strcmp(num, "reverse") == 0 && sum){  
                dir = -dir;  
                temp = tras;  
                tras = frente;  
                frente = temp;  
            }  
        }  
    }  
return 0;  
}  

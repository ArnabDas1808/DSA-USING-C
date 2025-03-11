#include <stdio.h>



int n, m;       
float x[20];   
int w[20];     
int p[20];     
float ratio[20]; 
float profit = 0.0;  


void swapFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}


void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sortItems() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) { 
                swapFloat(&ratio[j], &ratio[j + 1]);
                swapInt(&w[j], &w[j + 1]);  
                swapInt(&p[j], &p[j + 1]);  
            }
        }
    }
}


void greedyKnapsack() {
    int u = m;  

    for (int i = 0; i < n; i++) x[i] = 0.0; 
    for (int i = 0; i < n; i++) {
        if (w[i] <= u) {  
            x[i] = 1.0;  
            profit += p[i];
            u -= w[i];  
        } else { 
            x[i] = (float)u / w[i]; 
            profit += p[i] * x[i];  
            break; 
        }
    }
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &w[i]);
        printf("Enter value of item %d: ", i + 1);
        scanf("%d", &p[i]);
        ratio[i] = (float)p[i] / w[i]; 
    }

    printf("Enter maximum weight capacity: ");
    scanf("%d", &m);

    sortItems();    
    greedyKnapsack(); 

    printf("Maximum profit: %.2f\n", profit);
    
    return 0;
}

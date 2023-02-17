#include <stdio.h>
#include <malloc.h>

typedef struct Line {
        int n;
        double *a;
} Line;

typedef struct Matrix {
        int lines;
        Line *matr;


} Matrix;

int getInt(int * a) {
        int n;
        do {
                n = scanf("%d", a);
                if (n<0) {
                        return 0;
                }
                if (n==0) {
                        printf("%s\n", "Error! Repeat input");
                        scanf("%c", 0);
                }
        } while (n==0);
        return 1;
} 

int getDouble(double * a) {
        int n;
        do {
                n = scanf("%lf", a);
                if (n<0) {
                        return 0;
                }
                if (n==0) {
                        printf("%s\n", "Error! Repeat input");
                        scanf("%c", 0);
                }
        } while (n==0);
        return 1;
}

void erase(Matrix * a) {
        int i;
        for (i = 0; i < a->lines; ++i) {
                free(a->matr[i].a);
        }
        free(a->matr);
        a->lines = 0;
        a->matr = NULL;
}

int input(Matrix * rm) {
        const char *pr = "";
        int m; //кол-во строк матрицы
        int i, j;
        double *p;
        do {
                printf("%s\n", pr);
                printf("Enter number of lines: --> ");
                pr = "You are wrong; repeat, please!";
                if (getInt(&m) == 0) {
                        return 0;
                }

        } while (m<1);
        rm->lines = m;

        rm->matr = (Line *)calloc(m, sizeof(Line));

        for (i = 0; i < rm->lines; ++i){
                //для каждой строки вводим кол-во элементов
                pr = "";
                do {
                        printf("%s\n", pr);
                        printf("Enter number of items in line %d: --> ", i + 1);
                        pr = "You are wrong; repeat, please!";
                        if (getInt(&m) == 0) {
                                rm->lines = i;
                                erase(rm);
                                return 0;
                        }
                } while (m<1);
                rm->matr[i].n = m;
                p = (double *)malloc(sizeof(double) * m);
                rm->matr[i].a = p;


                //вводим элементы
                printf("Enter items for matrix line #%d:\n", i + 1);
                for (j=0; j<m; ++j, ++p) {
                        if (getDouble(p) == 0) {
                                rm->lines = i+1;
                                erase(rm);
                                return 0;
                        }
                }


        }
        return 1;


}




void output(const char *msg, Matrix a) {
        int i, j;
        double *p;
        printf("%s:\n", msg);
        for (i=0; i < a.lines; ++i) {
                p = a.matr[i].a;
                for (j=0; j<a.matr[i].n; ++j, ++p) {
                        printf("%10lf", *p);
                }
                printf("\n");

                
        }

}


int * sortIndex(int n, Matrix a) {
        int s[n];
        
        int i, j;
        int temp;
        double * p, * t;
        for (i=0;i<n;i++) {
                s[i] = i;
        }


        for (int i = 0; i < n - 1; i++) {
                for (int j = (n - 1); j > i; j--) // для всех элементов после i-ого
                {
                        p = a.matr[j - 1].a;
                        t = a.matr[j].a;
                        printf("%lf", *p);
                        if ( *p > *t ) // если текущий элемент меньше предыдущего
                        {               
                                int temp = s[j - 1]; // меняем их местами
                                s[j - 1] = s[j];
                                s[j] = temp;
                        }
                }           
        }
        int * ptr = s;
        return ptr;
}


int main() {


        Matrix matr = {0, NULL};
        double res;
        int i;
        if (input(&matr) == 0) {
                printf("%s\n", "End of file occured");
                return 1;
        }
        output("Source matrix", matr);
        //int * z = sortIndex(matr.lines, matr);
        
     
        //printf("%d", *(z+(matr.lines-1)));

       

         
    
 }


# include <stdio.h>
# include <string.h>

//Aeai?eoi Aaeeno?u

const int n = 5,m = 6;

void deikstra(int n, int lineWeights[n][m], int * pointWeights)
{
    int i = n, j, weight;
    for (j = 1; j <= n; j++)
    {
        if (j==i) continue;                             //Anee j niaiaaaao n i
        if (lineWeights[i][j]==0) continue;             //Anee j ia yaeyaony ninaaii
        weight = pointWeights[i] + lineWeights[i][j];
        if (weight < pointWeights[j])
            pointWeights[j] = weight;       //Anee iaeaaiiue aan iaiuoa oaeouaai, ia?acaienuaaai
    }

    lineWeights[i][i] = 1;              //Iiia?aai aa?oeio
    int mem = 0, min = 20000;           //Mem aoaao o?aieou iiia? ninaaa
    for (j = 1; j <= n; j++)
    {
        if (j==i) continue;                             //Anee j niaiaaaao n i
        if (lineWeights[i][j]==0) continue;             //Anee j ia yaeyaony ninaaii
        if (pointWeights[j] < min)
            mem = j;
    }

    if (mem > 0)
        deikstra(j,lineWeights,pointWeights);   //Aucuaaai deikstra io ninaaa n ieieiaeuiui aanii

    return;
}

int main(void)
{
    FILE *in = fopen("input.txt", "rt");
	if (!in)
           printf("File not found.\n");
//    fscanf(in,"%d %d",&n,&m);
 //   printf("%d  %d\n\n",n,m);

    int i,j;
    int matrix[n][m];
    int weights[n+1];
    for (i = 1; i <= n; i++)            //Eieoeaeecaoey
    {
        weights[i] = 20000;
        for (j = 1; j <= n; j++)
            matrix[i][j] = 0;
    }

    for (int k = 0; k < m; i++)
    {
        fscanf(in,"%d %d %d",&i,&j,&matrix[i][j]);
        printf("%d  %d  %d\n\n",i,j,matrix[i][j]);
        matrix[j][i] = matrix[i][j];
    }
    fclose(in);
	printf("\n");


    deikstra(1,matrix,weights);         //Ia?aaioea

    for (int k = 1; k <= n; k++)
        printf("1  --->   %d          %d\n\n",k,weights[k]);      //Auaia

	getchar();
    getchar();
	return 0;
}
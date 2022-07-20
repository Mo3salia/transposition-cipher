#include<stdio.h>
#include<string.h>

char ARR[30][30], Message[120], key[60], m[60], temp[60], temp2[60];
int Knum = 0,Dec;
void CreateCipher(int i, int r)
{
    int j;
    for (j = 0; j < r; j++)
    {
        {
            Message[Knum++] = ARR[j][i];
        }
    }
    
}

void makeArray(int col, float row)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        ARR[i][col] = temp2[i];
    }
}

int findMin()
{
    int i, j, min, index;

    min = temp[0];
    index = 0;
    for (j = 0; temp[j] != NULL; j++)
    {
        if (temp[j] < min)
        {
            min = temp[j];
            index = j;
        }
    }

    temp[index] = 123;
    return(index);
}
int main()
{
    char* message, * dmessage;


    float  Keylen, mlen;
    int i, j, row, column, min;
    int rows;
	printf("Enetr the key\n");
	gets_s(key);
    printf("\n");
    
	while (Dec != 1 && Dec != 2)
	{
		printf("Enter 1 to Encryption Enter 2 to Decryption\n");
        scanf_s("%d", &Dec);
	}
	if(Dec == 1)
	{ 
        printf("\nEnter the message want to Encrypt\n");
        gets_s(m);
        gets_s(m);
        printf("\n");
        message = m;

        strcpy_s(temp, key);
        Keylen = strlen(key);
        mlen = strlen(m);


        Knum = 0;
        for ( i = 0; i < (mlen / Keylen); i++)
        {
            

            for (j = 0; j < Keylen; j++)
            {
                if (message[Knum] == NULL)
                    ARR[i][j] = '-';
                else
                    ARR[i][j] = message[Knum++];
            }
        }
        row = i;
        column = j;
        printf("\nArray after sorting \n");
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                printf("%c ", ARR[i][j]);
            }
            printf("\n");
        }

        Knum = 0;

        for (i = 0; i < Keylen; i++)
        {
            min = findMin();
            CreateCipher(min, row);
        }

        Message[Knum] = '\0';
        printf("\nEncrypted message is\n");
        for (i = 0; Message[i] != NULL; i++)
            printf("%c", Message[i]);

        printf("\n");
	
	}
    else
    {
        printf("\nEnter the Cipher want to Decrypt\n");
        
        gets_s(m);
        gets_s(m);
        printf("\n");
        message = m;
        while (strlen(message) % strlen(key) != 0)
        {
            printf("\nthe cipher must be divided by the number of key elements \n");
            printf("\nEnter the Cipher want to Decrypt\n");
            gets_s(m);
            printf("\n");
            message = m;
        }
        strcpy_s(temp, key);
        Keylen = strlen(key);
        mlen = strlen(m);
        rows = mlen / Keylen;
        j = 0;
        row = rows;
        column =  Keylen;

        for (i = 0, Knum = 1; message[i] != NULL; i++, Knum++)
        {
            temp2[j++] = message[i];
            if ((Knum % rows) == 0)
            {
                temp2[j] = '\0';
                min = findMin();
                makeArray(min, rows);
                j = 0;
            }
        }

        printf("\nArray after sorting \n");

        Knum = 0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                printf("%c ", ARR[i][j]);
                //retrieving message
                Message[Knum++] = ARR[i][j];

            }
            printf("\n");
        }
        Message[Knum] = '\0';

        printf("\nMessage After Decryption\n");

        for (i = 0; Message[i] != NULL; i++)
            printf("%c", Message[i]);
        
        printf("\n");
    }

	return 0;

}


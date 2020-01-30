#include<stdio.h>

int main()
{
int n , s , k , j , i;
printf("\nenter number of the total sender message componets and the number of sets = ");
scanf("%d %d",&n,&s);
printf("\nEnter the number in binary one by one : \n");
int sen[n][s];
int tsen[n][s];
int temp;
int sum[s];
int carry = 0;
for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ;j < s ; j++)
			{
				scanf("%d",&sen[i][j]);
				tsen[i][j] = sen[i][j];
			}
		printf("\n");
	}

printf("\nTYPED NUMBERS ARE\n");
for(i = 0 ; i < n ; i++){

	for(j = 0 ;j < s ; j++)
		{
			printf("%d",sen[i][j]);
		}
	printf("\n");
	}
for(i = 0 ; i < n - 1 ; i++)
	{
		temp = 0;
		carry = 0;
		//printf("\nAA");
		for(k = 0 ; k < s ; k++)
			{
				sum[k] = 0;
			}
		for(j = s - 1 ; j > -1 ; j--)
			{
				temp++;
				if((sen[i][j]) == 0 && (sen[i + 1][j] == 1) && (carry == 0))
					{
						sum[j] = 1;
						carry = 0;
						//printf("\na");
					}		
				else if((sen[i][j]) == 0 && (sen[i + 1][j] == 0) && (carry == 0))
					{
						sum[j] = 0;
						carry = 0;
						//printf("\nb");
					}
				else if((sen[i][j]) == 0 && (sen[i + 1][j] == 0) && (carry == 1))
					{
						sum[j] = 1;
						carry = 0;
						//printf("\nc");
					}
				else if((sen[i][j]) == 1 && (sen[i + 1][j] == 0) && (carry == 0))
					{
						sum[j] = 1;
						carry = 0;
						//printf("\nd");
					}
				else if((sen[i][j]) == 0 && (sen[i + 1][j] == 1) && (carry == 1))
					{	
						sum[j] = 0;
						carry = 1;
						//printf("\ne");
					}
				else if((sen[i][j]) == 1 && (sen[i + 1][j] == 0) && (carry == 1))
					{
						sum[j] = 0;
						carry = 1;
						//printf("\nf");
					}
				else if((sen[i][j]) == 1 && (sen[i + 1][j] == 1) && (carry == 0))
					{
						sum[j] = 0;
						carry = 1;
						//printf("\ng");
					}
				else if((sen[i][j]) == 1 && (sen[i + 1][j] == 1) && (carry == 1))
					{
						sum[j] = 1;
						carry = 1;
						//printf("\nh");
					}
			}
//printf("Temp = %d",temp);
		if ( (carry == 1))
			{
				printf("\n");
				/*for(k = 0 ; k < s ; k++)
					{
						printf("%d",sum[k]);
					}
				*/
				//printf("\nK");
				for(k = s - 1 ; k > -1 ; k--)
					{
						if(carry == 1)
							{
							//	printf("\nK1");
								if(sum[k] == 0)
									{
									//	printf("\nK2");	
										sum[k] = 1;
										carry = 0;
										k = 0;
									}
							    else if(sum[k] == 1)
 								{
										//printf("\nK3");
										sum[k] = 0;
										carry = 1;
								}
							}
					}
			}
//printf("%d\n",sum[j]);
		for( k = 0 ; k < s ; k++)
			{
				sen[i+1][k] = sum[k];
			}
	}

printf("\nThe sum is = ");
for(i = 0 ; i < s ; i++)
{
printf("%d",sum[i]);
}
int checksum[s];
for(i = 0 ; i < s ; i++)
{
	if(sum[i] == 0)
	{
		checksum[i] = 1;
	}
	else
	{
		checksum[i] = 0;
	}
}
printf("\nThe Checksum is = ");
for(i = 0 ; i < s ; i++)
{
	printf("%d",checksum[i]);
}
printf("\nThe complete message bieng sent to the user is : ");
for(i = 0 ; i < n + 1 ; i++)
	{
		if( i < n){
		for(j = 0 ;j < s ; j++)
			{
				printf("%d",tsen[i][j]);
			}
		}
		else
		{
			for(k = 0 ; k < s ; k++)
			{
				printf("%d",checksum[k]);
			}
		}
	}
return 0;
}


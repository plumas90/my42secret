/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:02:34 by minpark           #+#    #+#             */
/*   Updated: 2024/07/09 23:15:55 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void slash2(int num, int *cha, int *arr);
void slash1(int num, int *cha, int *arr);
void per1(int num, int *cha, int *arr);
void per2(int num, int *cha, int *arr);
void ch_4(int *arr , int num);
int checkarr(int *numarr);
int nominus(int *cha);
#include <stdio.h>
#include <stdlib.h>

void    ch_zero(int *arr)
{
        int     i;
        int     j;
	int	num;

        i = 0;
        j = 0;
	num = 0;
        while(i < 4)
        {
                j = 0;
                while(j < 4)
                {
                        if(arr[i * 4 + j] == '0')
			{
	printf("10진 정수 출력(부호O) : %d\n", num);

				ch_4(arr , num);
			}
			num++;
                        ++j;
                }
                ++i;
        }
}
void del(int *a, int c)
{
	while(*a)
	{
		if(*a == c)
		{	
			write(1, &c, 1);
			*a = '0';
		}
		++a;
	}
}
void cha_set(int *cha)
{
	int i;

	i = 1;
	cha[0] = '1';
	cha[1] = '2';
	cha[2] = '3';
	cha[3] = '4';
	cha[4] = '9';
}

void ch_4(int *arr , int num)
{
	int numarr[5];
	int count;

	count =0;

	cha_set(numarr);
	per1(num, numarr, arr);
	per2(num, numarr, arr);
	slash1(num, numarr, arr);
	slash2(num, numarr, arr);

	write(1, "\n", 1);
	if(num == 1)
	{
		write(1, "okay?", 5);
	}

	count = checkarr(numarr);
	if(count == 1)
	{
		write(1, "countcheck'\n'", 11);
		arr[num] = nominus(numarr);
	}

}
int checkarr(int *numarr)
{
	int i;
	int count;
	      
        i = 0;
	count = 0;
	while (numarr[i] != '\0')
	{
		if (*numarr != '0' && *numarr != '9')
		{
			count++;
		}
		numarr++;
	}
	return count;
}
int nominus(int *cha)
{
	while(*cha != 99)
	{
		if(*cha != -1 && *cha != 99)
		{
			return (*cha);
		}
	}
	return (0);
}
void per1(int num, int *cha, int *arr)
{
	if(num % 4 == 0)
        {
                del(cha, arr[num + 1]);
                del(cha, arr[num + 2]);
                del(cha, arr[num + 3]);
        }
        if(num % 4 == 1)
        {
                del(cha, arr[num + 1]);
                del(cha, arr[num + 2]);
                del(cha, arr[num - 3]);
        }

}
void per2(int num, int *cha, int *arr)
{
	if(num % 4 == 2)
        {
                del(cha, arr[num + 1]);
                del(cha, arr[num - 1]);
                del(cha, arr[num - 2]);
        }
        if(num % 4 == 3)
        {
                del(cha, arr[num - 1]);
                del(cha, arr[num - 2]);
                del(cha, arr[num - 3]);
        }

}
void slash1(int num, int *cha, int *arr)
{
        if(num / 4 == 0)
        {
                del(cha, arr[num + 4]);
                del(cha, arr[num + 8]);
                del(cha, arr[num + 12]);
        }
        if(num / 4 == 1)
        {
                del(cha, arr[num + 4]);
                del(cha, arr[num + 8]);
                del(cha, arr[num - 4]);
        }
}

void slash2(int num, int *cha, int *arr)
{
	if(num / 4 == 2)
        {
                del(cha, arr[num + 4]);
                del(cha, arr[num - 4]);
                del(cha, arr[num - 8]);
        }
        if(num / 4 == 3)
        {
                del(cha, arr[num - 4]);
                del(cha, arr[num - 8]);
                del(cha, arr[num - 12]);
        }

}

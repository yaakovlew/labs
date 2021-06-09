#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actionvector.h"

int comp(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}





void menu(vector* tmp) {
	printf("0-EXIT\n 1 - for delete element\n 2 - for push back element\n 3 - for sort element from small to biggest\n 4 - for search element's index\n 5 - for change elements on  massive\n	6 - for connect 2 massivs\n");
	int n = 0;
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		printf("EXIT");
		return;
		break;
	case 1:
		printf("Which element u would like to delete:\n");
		int index;
		scanf("%d", &index);
		tmp->dell(tmp, index);
		break;
	case 2:
		printf("Wrinte nubmer, which the same with type of data");
		if (tmp->element_size == 1) {
            char element;
            scanf("%c", &element);
            while (!(65 <= (int) element && (int) element <= 122))
                scanf("%c", &element);
                tmp->push_back(tmp, &element);
        }
		else {
			double element;
			scanf("%lf", &element);
			tmp->push_back(tmp, &element);
		}
		break;
	case 3:
		qsort(tmp->mus, tmp->length, tmp->element_size, comp);
		break;
	case 4:
		printf("what element u would like to find?:");
		if (tmp->element_size == 1) {
			char element;
			scanf("%c", &element);
			tmp->search_index(*tmp, &element);
		}
		else {
			double element;
			scanf("%lf", &element);
			tmp->search_index(*tmp, &element);
		}
		break;
	case 5:

		break;
	case 6:
		printf("How much elements u would like to use?:");
		int length;
		scanf("%d", &length);
		if (tmp->element_size == 1) {
			char* a = (char*)calloc(length, 1);
		}
		else {

		}
		break;
	case 7:
		if (tmp->element_size == 1)
			for (int i = 0; i < tmp->length; i++)
				printf("%c ", *(char*)tmp->get_i(tmp, i));
		else
			for (int i = 0; i < tmp->length; i++)
				printf("%lf ", *(double*)tmp->get_i(tmp, i));
			printf("\n");
	default:
		break;
	}
	menu(tmp);
}
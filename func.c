#include <stdlib.h>
#include <stdio.h>
#include "func.h"
#include <math.h>


void read_data_mnist(FILE *mnist, int *data_set, int data_set_current_namber_of_elements, int *marked_ans_set, int marked_ans_set_current_namber_of_elements, int how_many_img) {
	int c, number_of_pixels = 284;
	data_set = (int*)realloc(data_set, (data_set_current_namber_of_elements + how_many_img)*sizeof(int));//довыделение места в массиве картинок
	marked_ans_set = (int*)realloc(marked_ans_set, (marked_ans_set_current_namber_of_elements + how_many_img)*sizeof(int));//довыделение места в массиве лейблов
	for (int i = 0; i < how_many_img; i++) {
		fscanf(mnist, "%d", c);
		marked_ans_set[how_many_img + i] = c;//дополнение массиво лейблов
		for (int j = 0; j < number_of_pixels; j++) {
			fscanf(mnist, "%d", c);
			data_set[how_many_img + i][j] = c;//дополнение массива картинок
		}
	}
} // читает из файла заданное кол-во картинок и записывает лейблы и значения пикселей в массивы


int get_info_about_layers(int *set_for_layers_info) {
	printf("how many layers do you want?\n");
	scanf("%d", number_of_layers);
	set_for_layers_info = (int*)realloc(set_for_layers_info, number_of_layers * sizeof(int));// перевыделение места под значения количества неиронов в каждом слое
	for (int i = 0; i < number_of_layers; i++) {
		printf("how many neurons %d layer consists of?\n");
		scanf("%d", number_of_neurons);
		set_for_layers_info[i] = number_of_neurons;// заполнение массива количества неиронов в слое
	}
	return number_of_layers; // записывает в массив сколько нейронов в каждом слое и возвращает кол-во слоев
}


double create_weights_between2_layers(int number_of_neurons_in_first_layer, int number_of_neurons_in_second_layer) {
	double** m;
	m = (double**)malloc(number_of_neurons_in_first_layer * sizeof(double*)); //выделение места под количество массивов с весами (веса от каждого неирона первого слоя)
	for (i = 0; i < N; i++) {  }

	for (int i = 0; i < number_of_neurons_in_first_layer; i++) {

		for (int j = 0; j < number_of_neurons_in_second_layer; j++) {
			m[i] = (double*)malloc(number_of_neurons_in_second_layer * sizeof(double)); // выделение места под вес для каждого неирона второго слоя от какого-то одного неирона первого
			n[i][j] = rand();
		}

	}
	return m; // двойной массив весов между двумя слоями
}

double create_neuron_values_for_all_layers(int number_of_layers, int *set_for_layers_info) {
	double*** m;
	m = (double**)malloc(number_of_layers * sizeof(double*));// выделение места под количество слоев
	for (int i = 0; i < number_of_layers, i++) {
		m[i] = (double*)malloc(set_for_layers_info[i] * sizeof(double));//выделение места под количество неиронов в слое

		for (int j = 0; j < set_for_layers_info[i], j++) {
			m[i][j] = (double*)malloc(2 * sizeof(double));//выделение места под значение неирона и его bias #плохо написано неэффективно 

			m[i][j][0] = 0; // значение каждого неирона
			m[i][j][1] = rand(); // bias каждого неирона
		}
	}
	return m; // значение[0] и bias[1] каждого нейрона в каждом слое   
}


double sigmoid(double numb) {
	int a;
	a = 1 / (1 + eps^(-x));
	return a;
}

// у нас проблема числа в массиве интовые а после сигмоида они становятся флоатами, возможное решение переделать массив весов и значений нейронов на флоаты
void frontprop(double* neuron_values_and_biases, double * set_for_weights, int number_of_layers, int set_for_layers_info, int* data_img, int data_size, int size_of_ouput) {
	double c;
	double* ans;
	for (int t = 0; t < set_for_layers_info[0]; t++) {
		 for (int k = 0; k < data_size; k++) {
			 neuron_values_and_biases[0][t][0] += (data_img[k] * set_for_weights[0][k][t]); //перепроверить я был сонным
		}
		 neuron_values_and_biases[0][t][0] -= neuron_values_and_biases[0][t][1];
		 //neuron_values_and_biases[0][t][0] = sigmoid(c); 
	}
	for (int i = 0; i < number_of_layers - 1; i++) {
		for (int j = 0; j < set_for_layers_info[i + 1], j++) {
			for (int s = 0; s < set_for_layers_info[i], s++) {
				neuron_values_and_biases[i + 1][j][0] += (sigmoid(neuron_values_and_biases[i][s][0]) * set_for_weights[i][s][j]);
			}
			neuron_values_and_biases[i][j][0] -= neuron_values_and_biases[i][j][1];
			//neuron_values_and_biases[i + 1][j][0] = sigmoid(c);
			}

		ans = (double*)malloc(size_of_ouput * sizeof(double));

		for (int x = 0; x < size_of_ouput]; x++) {
			for (int y = 0; y < set_for_layers_info[number_of_layers - 1]; y++) {
				ans[x] += (neuron_values_and_biases[number_of_layers][y][0] * set_for_weights[number_of_layers][y][x]); //перепроверить я был сонным
			}
			//c = ans[x];
			//ans[x] = sigmoid(c);
		}
	
	}
	return ans;


}




double assemble(int number_of_pixels, int number_of_output_neurons) { //number_of_pixels = 784, number_of_output_neurons = 10
	int* set_for_layers_info;
	double** set_for_weights;
	double** values_of_all_neurons;
	int a = 0, ;
	
	set_for_layers_info = (int*)malloc(1 * sizeof(int));
	a = get_info_about_layers(set_for_layers_info);
	set_for_weights = (double*)malloc((a + 1) * sizeof(double));
	values_of_all_neurons = create_neuron_values_for_all_layers(a, set_for_layers_info);
	set_for_weights[0] = create_weights_between2_layers(number_of_pixels, set_for_layers_info[0]);
	for (int i = 1; i < a - 1; i++) {
		set_for_weights[i] = create_weights_between2_layers(set_for_layers_info[i], set_for_layers_info[i + 1]);
	}
	set_for_weights[a + 1] = create_weights_between2_layers(set_for_layers_info[a - 1], number_of_output_neurons);
	return values_of_all_neurons, set_for_weights;
}


double get_cost_func(double* ans, double* right_result, int number_of_output_neurons) {
	double loss;
	for (int i = 0; i < number_of_output_neurons; i++) {
		loss += (sigmoid(ans[i]) - right_result[i]) ^ 2;
	}
	return loss;
}

double dersigm(x) {
	return (eps ^ (-x)) / ((1 + eps ^ (-x)) ^ (-2));
}



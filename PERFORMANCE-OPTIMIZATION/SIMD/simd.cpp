#include <immintrin.h> // Include AVX intrinsics
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE (1 << 24) // Define the size of the vectors (16 million floats)

void add_vectors_non_simd(float* a, float* b, float* result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
}

void add_vectors_simd(float* a, float* b, float* result, int n) {
    for (int i = 0; i < n; i += 8) { // Process 8 floats at once
        __m256 vec_a = _mm256_loadu_ps(&a[i]); // Load 8 floats from a
        __m256 vec_b = _mm256_loadu_ps(&b[i]); // Load 8 floats from b
        __m256 vec_result = _mm256_add_ps(vec_a, vec_b); // Add vectors
        _mm256_storeu_ps(&result[i], vec_result); // Store the result
    }
}

int main() {
    float *a = (float*)malloc(VECTOR_SIZE * sizeof(float));
    float *b = (float*)malloc(VECTOR_SIZE * sizeof(float));
    float *result_non_simd = (float*)malloc(VECTOR_SIZE * sizeof(float));
    float *result_simd = (float*)malloc(VECTOR_SIZE * sizeof(float));

    // Initialize the arrays
    for (int i = 0; i < VECTOR_SIZE; i++) {
        a[i] = (float)i;
        b[i] = (float)(VECTOR_SIZE - i);
    }

    // Measure non-SIMD addition time
    clock_t start_non_simd = clock();
    add_vectors_non_simd(a, b, result_non_simd, VECTOR_SIZE);
    clock_t end_non_simd = clock();
    double time_non_simd = (double)(end_non_simd - start_non_simd) / CLOCKS_PER_SEC;

    // Measure SIMD addition time
    clock_t start_simd = clock();
    add_vectors_simd(a, b, result_simd, VECTOR_SIZE);
    clock_t end_simd = clock();
    double time_simd = (double)(end_simd - start_simd) / CLOCKS_PER_SEC;

    // Print the results
    printf("Non-SIMD Time: %.6f seconds\n", time_non_simd);
    printf("SIMD Time: %.6f seconds\n", time_simd);

    // Free allocated memory
    free(a);
    free(b);
    free(result_non_simd);
    free(result_simd);

    return 0;
}

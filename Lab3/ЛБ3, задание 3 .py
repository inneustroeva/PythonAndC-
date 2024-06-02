def sum_numerical(tol=1e-6):
    total_sum = 0
    lim = 2000
    k = 1
    while abs(lim) > tol:
        lim = 13 / 2 ** (k - 1) + (-1) ** (k - 1) / (2 * 3 ** (k - 1))
        total_sum += lim
        k += 1
    return total_sum
numerical_series_sum = sum_numerical()
print(f"Сумма числового ряда: {numerical_series_sum}")
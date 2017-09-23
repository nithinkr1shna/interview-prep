def sqr(x):
   return x*x

def sum_of_sqrs(f, x, y):
    return f(x) + f(y)

print sum_of_sqrs(sqr, 4, 5)

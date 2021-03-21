#　how to test

```
ARG=`python test/generate_random_numbers.py 100`; ./push_swap $ARG
```

# how to count step

```
ARG=`python test/generate_random_numbers.py 100`; ./push_swap $ARG | wc -l
```

# how to check if stack is successfully sorted

```
ARG=`python test/generate_random_numbers.py 100`; ./push_swap $ARG | ./checker $ARG
```
#　How to test

```
bash
ARG=`python test/generate_random_numbers.py 100`; ./push_swap $ARG
```

# How to count step

```
bash
ARG=`python test/generate_random_numbers.py 100`; ./push_swap $ARG | wc -l | tr -d ' '
```

# How to check if stack is successfully sorted

```
bash
ARG=`python test/generate_random_numbers.py 100`; ./push_swap $ARG | ./checker $ARG
```

# start test.sh

```
cd test
sh test.sh
```
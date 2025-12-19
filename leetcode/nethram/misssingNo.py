def missing(arr):
    if len(arr) == 0 : return -1;
    n = len(arr)
    actual_sum = (n*(n+1))//2
    sum_received = sum(arr)

    missing_no = actual_sum - sum_received

    print(missing_no)

missing([2,0,1])

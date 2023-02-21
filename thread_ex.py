import threading
import queue

def worker(num, func, args, results):
    """
    Thread worker function that calls a function with arguments and puts the result onto a queue.
    """
    result = func(*args)
    results.put((num, result))

def call_function_with_threads(num_threads, func, args_list):
    """
    Calls a function with multiple threads.
    """
    results = queue.Queue()

    # Create threads
    threads = []
    for i in range(num_threads):
        t = threading.Thread(target=worker, args=(i, func, args_list[i], results))
        threads.append(t)

    # Start threads
    for t in threads:
        t.start()

    # Wait for threads to finish
    for t in threads:
        t.join()

    # Get results from queue
    output = []
    while not results.empty():
        output.append(results.get())

    return output




def my_function(x):
    return x * 2

args_list = [[1], [2], [3], [4], [5]]
results = call_function_with_threads(5, my_function, args_list)
print(results)
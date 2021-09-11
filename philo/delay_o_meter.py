import time
from statistics import mean


def measure() -> float:
    """
    Measure how much of delay this machine will add on average
    while performing a 200 millisecond sleep.
    Returns a float, indicating a delay in milliseconds
    """
    start = time.perf_counter_ns()
    time.sleep(200 / 1000)
    end = time.perf_counter_ns()
    delay = ((end - start) / 1000000) - 200
    return delay


if __name__ == "__main__":
    avgs = []

    print("Measuring delay", end="", flush=True)
    for i in range(0, 20):
        print(".", end="", flush=True)
        avgs.append(measure())
    print("\n")

    print(
        f"For 200ms of usleep this machine adds {mean(avgs):.3f}ms of delay on average"
    )
    d_max = max(avgs)
    d_min = min(avgs)
    print(f"Peak delay: {d_max:.3f}ms")
    print(f"Min delay: {d_min:.3f}ms")

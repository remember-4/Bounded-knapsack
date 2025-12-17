import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("time.out")

data["VN"] = data["V"] * data["N"]

plt.figure()
plt.plot(data["VN"], data["time_ms"], marker='o')
plt.xlabel("V × N")
plt.ylabel("Running Time (ms)")
plt.title("Actual Runtime vs V × N")
plt.grid(True)
plt.show()

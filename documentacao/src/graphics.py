import matplotlib.pyplot as plt
import numpy as np

# Valores do benchmark multithread
threads = ['1', '2', '4', '8', '12'] # Número de threads

# [finalOpenMP.c]
# tempo1 = [21, 9, 4.6, 4.6, 4.6]
# tempo2 = [13.5, 4.7, 1.7, 0.75, 0.5]

# [exampleOpenMP.c]
tempo1 = [15, 9, 6, 6, 6]
tempo2 = [11.3, 5.7, 3.2, 2.2, 1.8]

# [./x264]
# tempo1 = [259, 155, 103, 103, 103]
# tempo2 = [0, 0, 0, 0, 0]
# fps = [2.32, 3.87, 5.82, 5.82, 5.82]

# Criando o gráfico
bar_width = 0.3
plt.figure(figsize=(10, 6))
bar_positions1 = np.arange(len(threads)) - bar_width / 2
bar_positions2 = np.arange(len(threads)) + bar_width / 2
plt.bar(bar_positions1, tempo1, color='#f4bb12', alpha=0.7, width=bar_width, label='Rasp Pi')
plt.bar(bar_positions2, tempo2, color='#0078D7', alpha=0.7, width=bar_width, label='R5 5600')
plt.xlabel('Threads')
plt.ylabel('Tempo de exec')

# plt.title('finalOpenMP.c')
plt.title('exampleOpenMP.c')
# plt.title('./x264')

plt.xticks(np.arange(len(threads)), threads)
plt.grid(axis='y')
plt.legend()

# Adicionando a legenda para a unidade de tempo
plt.text(-0.92, max(max(tempo1), max(tempo2)) * 1.04, '(segundos)', fontsize=9)

# Adicionando o valor em segundos acima de cada barra
for i in range(len(threads)):
    plt.text(bar_positions1[i], tempo1[i] + 0.1, f'{tempo1[i]}', ha='center', va='bottom', fontsize=8)
    plt.text(bar_positions2[i], tempo2[i] + 0.1, f'{tempo2[i]}', ha='center', va='bottom', fontsize=8)
    # plt.text(bar_positions1[i], tempo1[i] - 8, f'{fps[i]} FPS', ha='center', va='bottom', fontsize=8, color='black')
    # plt.text(bar_positions2[i], tempo2[i] - 8, f'{0} FPS', ha='center', va='bottom', fontsize=8, color='black')


plt.tight_layout()

# Mostrando o gráfico
plt.show()

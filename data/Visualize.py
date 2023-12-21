import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

with open('results.txt', 'r') as f:
    lines = f.readlines()

data = {'Data Type': [], 'Tree Type': [], 'Operation': [], 'Time (ms)': []}
data_type = ''
operation = ''
for line in lines:
    if 'Comparing with' in line:
        data_type = line.split(' ')[2]
    elif 'BST insertion time' in line or 'AVL insertion time' in line:
        operation = 'Insertion'
        tree_type = 'BST' if 'BST' in line else 'AVL'
        data['Data Type'].append(data_type)
        data['Tree Type'].append(tree_type)
        data['Operation'].append(operation)
        data['Time (ms)'].append(float(line.split(': ')[1].split(' ')[0]))
    elif 'BST search time' in line or 'AVL search time' in line:
        operation = 'Search'
        tree_type = 'BST' if 'BST' in line else 'AVL'
        data['Data Type'].append(data_type)
        data['Tree Type'].append(tree_type)
        data['Operation'].append(operation)
        data['Time (ms)'].append(float(line.split(': ')[1].split(' ')[0]))

df = pd.DataFrame(data)

insertion_df = df[df['Operation'] == 'Insertion']
search_df = df[df['Operation'] == 'Search']

plt.figure(figsize=(10, 6))
sns.barplot(x='Data Type', y='Time (ms)', hue='Tree Type', data=insertion_df, errcolor=None)
plt.title('Insertion Times for BST and AVL Trees')
plt.yticks(np.arange(0, 105, 10))
plt.grid(True)
plt.legend(bbox_to_anchor=(1.05, 1), loc=2, borderaxespad=0.)
plt.savefig('./graphs/insertion_times.png', bbox_inches='tight')
plt.close()

plt.figure(figsize=(10, 6))
sns.barplot(x='Data Type', y='Time (ms)', hue='Tree Type', data=search_df, errcolor=None)
plt.title('Search Times for BST and AVL Trees')
plt.yticks(np.arange(0, 105, 10))
plt.grid(True)
plt.legend(bbox_to_anchor=(1.05, 1), loc=2, borderaxespad=0.)
plt.savefig('./graphs/search_times.png', bbox_inches='tight')
plt.close()
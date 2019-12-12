#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import matplotlib
import seaborn as sns
from IPython.core.getipython import get_ipython
import matplotlib.pyplot as plt
matplotlib.style.use('ggplot')



# In[2]:


data = [[4708625, 835200, 780187, 756146], 
        [2342636, 395239, 368997, 355727],
        [2385915,389766,366061,381589],
        [4129800,627849,611979,696966],
        [14640869,1792572,1875418,2759226]]


# In[3]:


df = pd.DataFrame(data, 
                  columns=['Book', 'DVD', 'Video', 'Music'], 
                  index=range(1,6))


# In[ ]:


df1=(df / df.sum()).plot(kind='bar')
df2=df.plot(kind='bar')
plt.show(df1)
plt.show(df2)


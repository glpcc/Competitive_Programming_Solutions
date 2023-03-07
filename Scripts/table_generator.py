#%%
import selenium
from selenium import webdriver
import pandas as pd
from selenium.webdriver.common.by import By

options = webdriver.ChromeOptions()
options.binary_location = r'C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe'
driver = webdriver.Chrome(r'C:\Users\gonza\Documents\selenium_web_driver\chromedriver.exe', chrome_options=options)

#%%
driver.get('https://www.aceptaelreto.com/user/profile.php')

input('Press enter when you have logged in: ')

#%%
table = driver.find_element('xpath',"//table")

print(table.get_attribute('class'))
# %%

problems_df = pd.DataFrame(columns=['Problem Number','Problem Name','Done'])


# %%

for elem in table.find_elements(By.TAG_NAME,'tr')[1:]:
    table_row = [elem.text[0:3],elem.text[6:],not (elem.get_attribute('class') == 'danger')]
    problems_df.loc[len(problems_df)] = table_row


# %%
problems_df.sort_values(by='Problem Number',key=lambda k: k.astype('int'))
# %%
f = open('Table.md','w',encoding='utf-8')

f.writelines(['|Problem Number|Problem Name|Done|Acepta el Reto Link|\n','|---|---|---|---|\n'])
for indx,i in problems_df.iterrows():
    f.write(f'|[{i[0]}](/Acepta_El_Reto/Vol{i[0][0]}/{i[0]})|')
    f.write(f"{i[1]}|{'✅' if i[2] else '❌'}|[link](https://www.aceptaelreto.com/problem/statement.php?id={i[0]})|\n")
f.close()
# %%

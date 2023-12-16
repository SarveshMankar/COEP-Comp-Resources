import pandas as pd
import numpy as np


# Reading the csv file
df_new = pd.read_csv('Account_Wise.csv')

# saving xlsx file
GFG = pd.ExcelWriter('demo.xlsx')
df_new.to_excel(GFG, index = False)

workbook  = GFG.book
worksheet = GFG.sheets['Sheet1']

worksheet.set_column('B:B', 10)
worksheet.set_column('C:C', 22)
worksheet.set_column('D:D', 22)
worksheet.set_column('E:E', 6)
worksheet.set_column('G:G', 40)

worksheet.set_landscape()

GFG.save()

from win32com import client
xlApp = client.Dispatch("Excel.Application")
books = xlApp.Workbooks.Open('D:\\Best_Projects\\Money\\Exports\\demo.xlsx')
ws = books.Worksheets[0]
ws.Visible = 1

ws.PageSetup.LeftMargin = 25
ws.PageSetup.TopMargin = 40
ws.PageSetup.BottomMargin = 20
ws.PageSetup.RightMargin = 25

#ws.PrintOut()
ws.ExportAsFixedFormat(0, 'D:\\Best_Projects\\Money\\Exports\\hello.pdf')
books.Close(SaveChanges=False)

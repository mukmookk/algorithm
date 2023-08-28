from datetime import datetime, timedelta
from dateutil.relativedelta import relativedelta

def solution(today, terms, privacies):
    endtime = datetime.strptime(today, "%Y.%m.%d")
    
    term_dict = {term.split()[0]: int(term.split()[1]) for term in terms}
    
    priv_dict_list = []
    for val in privacies:
        date_str, kind = val.split()
        date_obj = datetime.strptime(date_str, "%Y.%m.%d")
        duration = term_dict[kind]
        term_date = date_obj + relativedelta(months=duration) - timedelta(days=1)
        priv_dict = {
            'date': date_obj,
            'duration': duration,
            'term_date': term_date
        }
        priv_dict_list.append(priv_dict)
    
    result = [
        idx + 1 for idx, val in enumerate(priv_dict_list) 
        if val['term_date'] < endtime
    ]
    
    return result
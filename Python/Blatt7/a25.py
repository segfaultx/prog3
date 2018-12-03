def devocalize(s):  # A25
    "Entfernt unnötige Vokale aus gegebenem String"
    res = ""
    for ele in s:
        if not ele in "aeiouAEIOU":
            res += ele
    return res


print(devocalize("Das ist ein Baerenspass."))
help(devocalize)  # A26

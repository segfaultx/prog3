#!/usr/bin/env python3

# I

wohnorte_male = [name.split(";")[4].strip() for name in open("a36-bonz.txt") if name.split(";")[0] == "Herr"]
print(sorted(wohnorte_male))

# II

gehalt_female = [sum(int(gehalt.split(";")[3]) for gehalt in open("a36-bonz.txt") if gehalt.startswith("Frau"))]
print(gehalt_female)

# III

wohnorte_male_rich = sorted([name for name in [name.split(";") for name in open("a36-bonz.txt") if
                                               name.split(";")[2].startswith("J")]], key=lambda x: int(x[3]),
                            reverse=True)[:1]
print(wohnorte_male_rich[0][4].strip())

# IV

hass_worte = [f"{name[0]} {name[1]} bekommt mehr, als {'er' if name[0] == 'Herr' else 'sie'} verdient!" for name in [name.split(";") for name in
                                                                                            [name for name in
                                                                                             open("a36-bonz.txt") if
                                                                                             int(name.split(";")[
                                                                                                     3]) > 100000]]]
print(hass_worte)

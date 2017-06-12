'''
generates test cases files in batch using code provided
at http://inf.ufrgs.br/~mrpritt/doku.php?id=inf05016:2017-1-trabalhos

ns_espo: represent the numbers of vertexes (n) of each set to generate cases where
for each value n_expo in the list, the number of vertexes in each set is 2^n_expo.
ms_prob: probabilities of each edge existing
'''

ns_expo = [10,11,12,13,14,15]
ms_prob = [0.001, 0.01, 0.02]

for n_expo in ns_expo:
    for m_prob in ms_prob:
        n = str(2**n_expo)
        p = str(m_prob)
        print "./gen " + n + " " + p + " > n" + "2tothe"+ str(n_expo) + "p" + p+ ".gr"   

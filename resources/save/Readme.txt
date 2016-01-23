### Les fichiers de sauvegarde au format .dat serviront à enregistrer le contenu d'une cave. Ce document décrit le format utilisé ###

## Les commentaires sont exclusivemet uniligne et commencent par un "#"

title_nb_cols=<nombre de colonnes pour les rubriques concernant une bouteille>
wine_nb_rows=<nombre de lignes utilisées pour enregistrer les différents vins>

# Les titres des colonnes sont renseignés en premier dans le document. Les changements de colonnes se matérialisent pas un séparateur "||"

Couleur||Domaine||Complément||Millésime||Région||Data d'achat||Stock

## Chaque vin est stocké sur une ligne de ce document, en matérialisant un changement de colonne par le séparateur "||"

Blanc||Domaine G.Bouton||Meursault 1er cru Les Charmes||Bourgogne||2013||2015||3
Blanc||Domaine de la Chapelle||Meursault||Bourgogne||2013||2015||3
Blanc||Domaine de la Chapelle||Santenay 1er cru||Bourgogne||2013||2015||3
Rouge||Domaine F.Gay||Corton Renardes (GC)||Bourgogne||2011||2015||3


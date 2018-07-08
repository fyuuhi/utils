DIR="/gpfs/fs2001/yfukuhar/data/Data_default_AOD/*"
LISTNAME="./Data_default_AOD.list"


for filepath in ${DIR}; do
  echo $filepath | tee -a ${LISTNAME}
done

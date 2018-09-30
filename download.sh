DIR=/gpfs/fs2001/yfukuhar/data/data18_rate/
DID1=user.yfukuhar.00359918.physics_Main.YFTAP.f969_m2020_RateJPZtapv4_EXT0
DID2=
DID3=
DID4=

DIDS="${DID1} ${DID2} ${DID3} ${DID4}"

for id in ${DIDS}
do
    #rucio download --ndownloader 5 $id
    #cd $id
    #hadd -k -f merged.root user.ynoguchi.*.root
    #rm user.ynoguchi.*
    cd $DIR
    echo $PWD
    rucio download --ndownloader 5 $id
    cd -
done

#echo ""
#for id in ${DIDS}
#do 
#    echo -e "==== DID ========\e[32;1m"
#    echo -e $id "\e[m"
#    echo "--"
#    echo "scp -r ${USER}@${HOSTNAME}:/tmp/${USER}/$id ./"
#done
#echo ""

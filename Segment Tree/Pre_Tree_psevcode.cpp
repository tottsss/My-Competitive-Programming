Pre segment tree
T holds the lowest key present in the range [b,e)
T's left son is a PreTree on values [b,b+e2)
T's right son is a PreTree on values [b+e2,e)


"Merging two PreSegment Trees"
function Merge(T1, T2, b, e){
  if T1 is empty then return T2
  if T2 is empty then return T1
  
  m = (b + e) / 2
  if T1.k > T2.k then swap T1 and T2
  T1.l = Merge(T1.l, T2.l, b, m)
  T1.r = Merge(T1.r, T2.r, m, e)
  T2.l = T2.r = empty
  
  if T1.k != T2.k:    
    ## We have to insert T2 into the corresponding child
    if T2.k >= m:
      T1.r = Merge(T1.r, T2, m, e)
    else:
      T1.l = Merge(T1.l, T2, b, m)
  return T1 
}
In order to insert a key into the tree, just merge it with a singleton tree. 



In order to find the greatest key smaller than a given k, one can do the following:
function Smaller(T, k){
  if T is empty or T.k >= k:
    return NOT_FOUND
  ret = Smaller(T.r, k)
  if ret is NOT_FOUND:
    ret = Smaller(T.l, k)
  if ret is NOT_FOUND:
    ret = T
  return ret
}

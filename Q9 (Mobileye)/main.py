def find_all_subsets(l):
    if(len(l) == 0 ):
        return []

    all_subsets = []
    for i in range(len(l)):
        subset_i = [[l[i]]]
        for l2 in  find_all_subsets(l[i+1:]):
            new_list = l2 + [l[i]] 
            subset_i.append(new_list)

        all_subsets += subset_i

    return all_subsets


print(find_all_subsets([1,2]))
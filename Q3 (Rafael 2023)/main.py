def calculateQuantityFromJars(state,quantity,pastStates):
    newPastStates = pastStates.copy()
    newPastStates.append(state)
    # print(state)

    if(state in pastStates):
        return 0
    
    if(quantity in state.values()):
        print("solution found")
        print(newPastStates)
        return 1

    

    for jar_x,val_x in state.items():
        if(val_x == 0): 
            newState = state.copy()
            newState[jar_x] = jar_x  #fill the empty jar
            if(calculateQuantityFromJars(newState,quantity,newPastStates.copy())): 
                return 1

        for jar_y,val_y in state.items():
            if(jar_x != jar_y and val_x !=0 and val_y!= jar_y): # if the jar are different 
                                                                # and the firt jar is not empty
                                                                # and the second jar is not full.
                newState = state.copy()
                val_transfered = min(val_x ,jar_y - val_y)  # Or we transfered all the quantity of the first jar
                                                            # or we transfered the quantity to fill the second jar.
                newState[jar_x] -= val_transfered
                newState[jar_y] += val_transfered
                if(calculateQuantityFromJars(newState,quantity,newPastStates.copy())): 
                    return 1

        if(val_x != 0):
            newState = state.copy()
            newState[jar_x] = 0  #empty the non-empty jar
            if(calculateQuantityFromJars(newState,quantity,newPastStates.copy())): 
                return 1

    return 0




def computeAllNextStates(state): # Input: array --> Output: array of array
    allNextStates = []

    for jar_x,val_x in state.items():

        if(val_x == 0): 
            newState = state.copy()
            newState[jar_x] = jar_x  #fill the empty jar
            allNextStates.append(newState)

        for jar_y,val_y in state.items():
            if(jar_x != jar_y and val_x !=0 and val_y!= jar_y): # if the jar are different 
                                                                # and the firt jar is not empty
                                                                # and the second jar is not full.
                newState = state.copy()
                val_transfered = min(val_x ,jar_y - val_y)  # Or we transfered all the quantity of the first jar
                                                            # or we transfered the quantity to fill the second jar.
                newState[jar_x] -= val_transfered
                newState[jar_y] += val_transfered
                allNextStates.append(newState)

        if(val_x != 0):
            newState = state.copy()
            newState[jar_x] = 0  #empty the non-empty jar
            allNextStates.append(newState)
            
    return allNextStates


def calculateQuantityFromJarsV2(allStates,quantity):
    newAllStates = allStates.copy()

    for state in allStates:
        allNextStates = computeAllNextStates(state)
        newAllStates += allNextStates

    for state in newAllStates:
        if(quantity in state.values()):
            print("solution found")
            newAllStatesNoDuplicate = []
            [newAllStatesNoDuplicate.append(x) for x in newAllStates if x not in newAllStatesNoDuplicate]
            print(newAllStatesNoDuplicate)
            print(len(newAllStatesNoDuplicate))
            return 1


    return calculateQuantityFromJarsV2(newAllStates,quantity)
    # print(state)

    

    return 0


def main():
    print("main function called")
    allStates = [dict([(3, 0), (5, 0),(7,0),(100,0)])]    #(capacity,quantity)
    quantity_to_find = 97
    calculateQuantityFromJarsV2(allStates,quantity_to_find)
    # print(computeAllNextStates(allStates[0]))
    
if __name__ == "__main__":
    main()
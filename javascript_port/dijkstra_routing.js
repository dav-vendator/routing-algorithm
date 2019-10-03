/*
Author: Dav Vendator
Name: A trivial implementation of Dijkstra Shortest Path
Status: Under development (currently doesn't tell which way to go)
Lang: Js
*/

const  adjacencyList = [] 
const inf = 1 << 62 

const sortList = (currentList) => {
    for (i = 0;  i < currentList.length;  i++) {
        for (j = 0;  j < currentList.length;  j++) {
            if (currentList[j][2] > currentList[i][2]) {
                temp = currentList[j]
                currentList[j] = currentList[i]
                currentList[i] = temp
            }
            // console.log("Current List:\n")
            // console.log(currentList)
        }
    }
}

const addEdge = (u, v, cost) => {
    if ( adjacencyList[u] === undefined) {
         adjacencyList.push([]) 
    }
     adjacencyList[u].push([v, cost]) 
}

const updateGraph = () => {
    //u
    addEdge(0, 1, 2) 
    addEdge(0, 2, 1) 
    addEdge(0, 3, 5) 
    //v
    //addEdge(1, 0, 2) 
    addEdge(1, 3, 3) 
    addEdge(1, 2, 2) 
    //x
    addEdge(2, 3, 3) 
    addEdge(2, 4, 1) 
    //w
    addEdge(3, 5, 5) 
    addEdge(3, 4, 1) 
    //y
    addEdge(4, 5, 2) 
    addEdge(4, 3, 1) 
    //d
    addEdge(5, 0, 10) 
}

const Neighbor = (s) => {
    if (s >  adjacencyList.length) {
        console.log(`Error`) 
        return 
    }
    neighbor = [] 
    try {
         adjacencyList[s].forEach((value_) => {
            neighbor.push(value_) 
        })
    } catch (error) {
        return []
    }
    return neighbor 
}

const FindAllPaths = (from) => {
    paths = []  //shortest paths
    currentList = [] 
    let cost = 0 
    paths.push([from, from, cost]) 
    neighbor = Neighbor(from) 

    if (neighbor !== undefined) {
        for (i = 0;  i < neighbor.length;  i++) {
            paths.push([from, neighbor[i][0], neighbor[i][1]]) 
        }

        //Appending all those nodes for which no known path yet exists
         adjacencyList.forEach((_value, index) => {
            flag = true
            for (i = 0; i < paths.length;  i++) {
                if (paths[i][1] == index) {
                    flag = false
                    break 
                }
            }
            if (flag) {
                paths.push([from, index, inf]) 
            }
        })

        //Appending all the nodes in currentList (except the source itself)
        currentList = paths.slice(1, paths.length) 
        //console.log(currentList)
        //Computing least cost path's cost
        while (currentList.length > 0) {
            sortList(currentList)

            currentElement = currentList[0] 
            currentList.splice(0, 1) 
            cost = currentElement[2] 
            //newCost(u, v) = min(oldCost(u,v), cost(u,x) + cost(x, v))
            Neighbor(currentElement[1]).forEach((value, _index) => {
                paths.forEach((path, i) => {
                    if (path[1] == value[0] && path[2] > value[1] + cost){
                        paths[i][2] = value[1]+cost
                    }
                })
            })
        }
         return paths
    }
}

updateGraph() 

for (i in  adjacencyList) {
    console.log(`Path for ${i}\n`)
    FindAllPaths(i).forEach((value, _index) => {
        console.log(`From: ${value[0]} to ${value[1]} path with shortest distance ${value[2]} exist.`)
    })
    console.log("\n")
}
package main

import (
	"fmt"
    "os"

	"github.com/LER0ever/Israfil/HttpAPI/base"
)

//InitialVersionPrint Print startup info
func InitialVersionPrint() {
	fmt.Print(
		base.AppName,
		"\nVersion: ",
		float64(base.AppVersion)/100.0,
		"\nApiLevel: ",
		float64(base.APILevel)/100.0,
		"\n\n")
}


func StopSystem() {
    fmt.Println("Call StopSystem()")
    for i := 0; i < 3; i++ {
        fmt.Printf("stopping clients[%d]\n", i)
        defer clients[i].Close()
        //log.Println(err)
        fmt.Printf("stopped clients[%d]\n", i)
    }
    os.Exit(0)
    /*for i := 0; i<3; i++ {
        ps[i].client.Close()
    }*/
    //res, err:= ps[0].Unload(PluginList[0])
    //log.Println(res, err)
}

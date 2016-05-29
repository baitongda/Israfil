package main

import (
	"log"
	"net/rpc"
	"net/rpc/jsonrpc"
	"os"
    "runtime"

	"github.com/LER0ever/Israfil/HttpAPI/base"
)

//PLUGINPREFIX e.g. icpNetease
const PLUGINPREFIX string = "icp"

//MAXPLUGINNUM the maximum num of plugins
const MAXPLUGINNUM uint = 10

var fext string
var fpre string
var clients [MAXPLUGINNUM]*rpc.Client
var ps [MAXPLUGINNUM]plug

//PluginList List of plugins that should be loaded on startup
var PluginList = []string{
	"Netease",
	"QQMusic",
	"Xiami",
	//	"Kuwo",
	//	"Kugou",
}

//StartPluginSystem Currently starts one by one
//TODO: concurrent startup
func StartPluginSystem() {
	log.SetPrefix("IsrafilCore::Main:: ")

	if runtime.GOOS == "windows" {
		fext += ".exe"
		fpre = ""
	} else {
		fext = ""
		fpre = "./"
	}
	for i, PN := range PluginList {
		log.Print("Initiating Plugin ", i, " ", fpre+PLUGINPREFIX+PN+fext)
		client, err := base.StartProviderCodec(jsonrpc.NewClientCodec, os.Stderr, fpre+PLUGINPREFIX+PN+fext)
		if err != nil {
			log.Fatalf("Error running plugin: %s", err)
		}
		clients[i] = client
		//defer clients[i].Close()
		ps[i] = plug{clients[i]}
		res, err := ps[i].Ping(PluginList[i])
		if err != nil {
			log.Fatalf("error communicating with Plugin: %s", err)
		}
		log.Printf("%s", res)
		//log.Printf("Plugin: %s", PLUGINPREFIX+PN+fext)
	}
	//SearchTest()
}


type plug struct {
	client *rpc.Client
}

func (p plug) Ping(name string) (result string, err error) {
	err = p.client.Call(name+".Ping", "ping", &result)
	return result, err
}

/*func (p plug) Unload(name string) (result bool, err error) {
    err = p.client.Call(name+".Unload", "Unload", &result)
    return result, err
}*/

func (p plug) Search(pluginname string, songname string) (retSR base.SearchRet, err error) {
	var tempSR base.SearchRet
	err = p.client.Call(pluginname+".Search", songname, &tempSR)
	log.Println(tempSR)
	return tempSR, err
}

/////////////DEBUG TEST

//NeteaseSearchTest  test
/*
func SearchTest() {
	numofsongs, err := ps[0].Search("Netease", "盛世回首")
	if err != nil {
		log.Fatalf("API CALL Netease Search Error: %s", err)
	}
	log.Printf("Search Ret Num of Songs: %d", numofsongs)
}
*/

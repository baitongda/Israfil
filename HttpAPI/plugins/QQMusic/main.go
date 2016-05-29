package main

import (
	"log"
	"net/rpc/jsonrpc"
	"fmt"
	"strconv"

	//	"github.com/ddliu/go-httpclient"
	"github.com/LER0ever/Israfil/HttpAPI/base"
	//"github.com/natefinch/pie"
)

func main() {
	log.SetPrefix("IsrafilCore::Plugin::QQMusic:: ")
	initHTTPClient()

	//if DEBUG == 1 {
	//	debugTest()
	//}

	p := base.NewProvider()
	if err := p.RegisterName("QQMusic", api{}); err != nil {
		log.Fatalf("failed to register Plugin: %s", err)
	}
	p.ServeCodec(jsonrpc.NewServerCodec)

}

type api struct{}

func (api) Ping(msg string, response *string) error {
	if msg != "ping" {
		*response = "Plugin Failed"
		return nil
	}
	log.Printf("Successfully Connected to host IsrafilCore::Main")

	*response = "IsrafilCore::Plugin::QQMusic Plugged"
	return nil
}

func (api) Search(name string, retSR *base.SearchRet) error {
	var Qmsr QMSearchRet
	searchByName(name, &Qmsr)
	log.Printf("Qmsr.Data.Song.Curnum: %d", Qmsr.Data.Song.Curnum)
    log.Print("QMSR::\n", Qmsr)
    log.Print("QMSR List Count", len(Qmsr.Data.Song.SongLists))
	retSR.NumOfRes = Qmsr.Data.Song.Curnum
	for i, song := range Qmsr.Data.Song.SongLists {
        log.Printf("DEBUG: Qmsr num %d", i)
		var tempS base.Song
		FArray := splitF(song.FString)
		tempmid, _ := strconv.Atoi(FArray[FMusicID])
		mid := int64(tempmid)
		retSR.Songs = append(retSR.Songs, tempS)
		retSR.Songs[i].UID = fmt.Sprintf("%d%s", base.SrcQQMusic, FArray[FSongID])
		retSR.Songs[i].Name = FArray[FSongName]
		retSR.Songs[i].ID = mid
		retSR.Songs[i].Source = base.SrcQQMusic
		retSR.Songs[i].URL = fmt.Sprintf(QMSongURL, FArray[FMusicID])
	}
	return nil;
}

package main

import (
    "fmt"
    //"net/url"
    //"strings"
    "html"
    "net/http"
    "io/ioutil"
    //"log"
    //"encoding/json"
)

func main() {
    http.HandleFunc("/", handler)
    http.ListenAndServe(":9001", nil)
}

func handler(w http.ResponseWriter, r *http.Request) {
    r.ParseForm()
    fmt.Fprintf(w, "Server Slice: 5s", html.EscapeString(r.URL.Path[1:]))
    fmt.Println("Http Method: ", r.Method)
    if r.Method == "POST" {
    result, _:= ioutil.ReadAll(r.Body)
    r.Body.Close()
    fmt.Printf("%s\n", result)
    }
}



/world
	view = "15x15"
	icon_size = 32
	cache_lifespan = 21
	hub = "Exadv1.spacestation13"
	hub_password = "kMZy3U5jJHSiBQjr"
	name = "/tg/ Station 13"
	fps = 20
	visibility = 0
/world/New()
	if(params["redirect_target"])
		redirect_target = params["redirect_target"]

/var/redirect_target = "byond://sybil.game.tgstation13.org:1337"



/client
	preload_rsc = 2
	var/blah = './redirect.dm'

/client/New(topic)
	..()
	winset(src, null, "command=.options") //other wise the user never knows if byond is downloading resources
	src << browse("<a href=\"[redirect_target]?[topic]\">Now redirecting you, click here if you are not taken to game server automatically.</a>", "window=browseroutput")
	src << link("[redirect_target][topic ? "?[topic]" : ""]")

/turf
	icon = 'stub.dmi'
/mob
	icon = 'stub.dmi'
/obj
	icon = 'stub.dmi'

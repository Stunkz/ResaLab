import pcbnew

board = pcbnew.GetBoard()

cx = pcbnew.FromMM(50)
cy = pcbnew.FromMM(50)
n_turns = 4
track_width = pcbnew.FromMM(1.0)
gap = pcbnew.FromMM(0.5)
start_size = pcbnew.FromMM(25)

for i in range(n_turns):
    size = start_size - i * gap
    pts = [
        (cx - size, cy - size),
        (cx + size, cy - size),
        (cx + size, cy + size),
        (cx - size, cy + size),
        (cx - size, cy - size)
    ]
    for j in range(len(pts)-1):
        t = pcbnew.PCB_TRACK(board)
        t.SetStart(pcbnew.VECTOR2I(int(pts[j][0]), int(pts[j][1])))
        t.SetEnd(pcbnew.VECTOR2I(int(pts[j+1][0]), int(pts[j+1][1])))
        t.SetWidth(int(track_width))
        t.SetLayer(pcbnew.F_Cu)
        board.Add(t)

pcbnew.Refresh()
print("Antenne NFC générée !")

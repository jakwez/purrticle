import * as flatbuffers from "flatbuffers";
import { Scene } from "./generated/purrticle/scene.js";
import { Renderer } from "./renderer.js";

const canvas = document.getElementById("canvas") as HTMLCanvasElement;
const status = document.getElementById("status")!;
const renderer = new Renderer(canvas);

function connect() {
  const ws = new WebSocket(`ws://${location.host}/ws`);
  ws.binaryType = "arraybuffer";

  ws.onopen = () => {
    status.textContent = "connected";
  };

  ws.onmessage = (event: MessageEvent<ArrayBuffer>) => {
    const buf = new flatbuffers.ByteBuffer(new Uint8Array(event.data));
    const scene = Scene.getRootAsScene(buf);
    renderer.draw(scene);
  };

  ws.onclose = () => {
    status.textContent = "disconnected";
    // status.textContent = "disconnected — retrying…";
    // setTimeout(connect, 2000)
  };

  ws.onerror = () => {
    status.textContent = "error";
  };
}

connect();

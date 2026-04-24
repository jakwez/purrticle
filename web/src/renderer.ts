import { Scene } from "./generated/purrticle/scene.js";

export class Renderer {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;

  constructor(canvas: HTMLCanvasElement) {
    this.canvas = canvas;
    this.ctx = canvas.getContext("2d")!;
  }

  draw(scene: Scene) {
    const extents = scene.extents();
    if (!extents) return;

    this.canvas.width = extents.x();
    this.canvas.height = extents.y();

    this.ctx.fillStyle = "#c0c0c0";
    this.ctx.strokeStyle = "#000000";
    this.ctx.lineWidth = 1;
    this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);
    this.ctx.rect(0, 0, this.canvas.width, this.canvas.height);
    this.ctx.stroke();

    this.ctx.fillStyle = "#ff00ff";
    this.ctx.strokeStyle = "#000000";
    this.ctx.lineWidth = 1;
    const r = 2;
    for (let i = 0; i < scene.particlesLength(); i++) {
      const p = scene.particles(i);
      if (!p) continue;
      this.ctx.beginPath();
      this.ctx.arc(p.x(), p.y(), r, 0, Math.PI * 2);
      this.ctx.fill();
      this.ctx.stroke();
    }
  }
}

import { defineConfig } from 'vite'

export default defineConfig({
  server: {
    host: '0.0.0.0',  // accessible from all LAN devices
    port: 5173,
    proxy: {
      '/ws': {
        target: 'ws://localhost:12345',
        ws: true,
      }
    }
  }
})
